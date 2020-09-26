public void calculaTotalRecebido(){
  new Thread() {

    @Override
    public void run() {
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
  }.start();

}