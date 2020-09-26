public void calculaTotalRecebido(){
    //Recebe aproximadamente 70mil registros.
    List<HistoricoRecebimento> recebidos = getListRecebimentos();
    Integer soma = 0;

    for(HistoricoRecebimento h1: recebidos){
      soma = soma + recebidos.getValorRecebido();
    }

    Integer porcentagemImposto = getReajusteAtualFromWebService();

    soma = soma + ((porcentagemImposto/100)*soma);

    retornaParaWebServiceValorTotal(soma);
  }