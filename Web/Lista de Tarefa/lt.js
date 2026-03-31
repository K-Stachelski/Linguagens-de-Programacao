
    const input = document.getElementById('novaTarefa');
    const btnAdd = document.getElementById('btnAdd');
    const lista = document.getElementById('lista');
    const contador = document.getElementById('contador');
    const btnLimpar = document.getElementById('btnLimparConcluidas');

    // Chave do localStorage
    const STORAGE_KEY = 'minha_lista_tarefas_v1';

    // Carrega tarefas do localStorage (se existir)
    let tarefas = JSON.parse(localStorage.getItem(STORAGE_KEY) || '[]');

    function salvar(){
      localStorage.setItem(STORAGE_KEY, JSON.stringify(tarefas));
    }

    function atualizarContador(){
      const n = tarefas.length;
      contador.textContent = n + (n === 1 ? ' tarefa' : ' tarefas');
    }

    function criarItemHTML(t){
      // t = { id, texto }
      const li = document.createElement('li');
      li.className = 'tarefa';
      li.dataset.id = t.id;

      const left = document.createElement('div');
      left.className = 'left';

      const span = document.createElement('span');
      span.className = 'texto';
      span.textContent = t.texto;

      left.appendChild(span);

      const acoes = document.createElement('div');
      acoes.className = 'acoes';

      const btnDelete = document.createElement('button');
      btnDelete.className = 'delete';
      btnDelete.title = 'Apagar tarefa';
      btnDelete.setAttribute('aria-label', 'Apagar tarefa');
      btnDelete.textContent = 'Apagar';
      btnDelete.addEventListener('click', ()=>{
        apagarTarefa(t.id);
      });

      acoes.appendChild(btnDelete);

      li.appendChild(left);
      li.appendChild(acoes);

      return li;
    }

    function render(){
      // Limpa a lista no DOM
      lista.innerHTML = '';
      // Adiciona cada tarefa
      tarefas.forEach(t => lista.appendChild(criarItemHTML(t)));
      atualizarContador();
      salvar();
    }

    function adicionarTarefa(texto){
      const txt = texto && texto.trim();
      if(!txt) return;
      const novo = { id: Date.now().toString(36) + Math.random().toString(36).slice(2,6), texto: txt };
      tarefas.unshift(novo); // coloca no topo
      render();
      input.value = '';
      input.focus();
    }

    function apagarTarefa(id){
      const idx = tarefas.findIndex(t => t.id === id);
      if(idx === -1) return;
      tarefas.splice(idx,1);
      render();
    }

    // Limpar tudo (confirmação simples)
    btnLimpar.addEventListener('click', ()=>{
      if(tarefas.length === 0) return;
      if(confirm('Deseja realmente apagar todas as tarefas?')){
        tarefas = [];
        render();
      }
    });

    // Eventos de adicionar
    btnAdd.addEventListener('click', ()=> adicionarTarefa(input.value));
    input.addEventListener('keydown', (e)=>{
      if(e.key === 'Enter'){
        adicionarTarefa(input.value);
      }
    });

    // Inicializa
    render();
