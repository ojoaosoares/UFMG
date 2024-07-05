module tb_mod_seven;

  reg N3, N2, N1, N0;             // Entradas N3, N2, N1, N0
  wire REMAINDER2, REMAINDER1, REMAINDER0;   // Saídas REMAINDER2, REMAINDER1, REMAINDER0

  // Instanciando o módulo mod_seven que estamos testando
  mod_seven uut (
    .A(N3),
    .B(N2),
    .C(N1),
    .D(N0),
    .OUT2(REMAINDER2),
    .OUT1(REMAINDER1),
    .OUT0(REMAINDER0)
  );

  // Procedimento de teste
  initial begin
    
    // Abre o arquivo VCD para gravação
    $dumpfile("dump.vcd");
    // Registra as variáveis que você deseja monitorar
    $dumpvars(0, tb_mod_seven);
    
    // Teste 16 combinações possíveis de entradas
    for (int i = 0; i < 16; i = i + 1) begin
      // Converte o contador em binário de 4 bits para as entradas
      {N3, N2, N1, N0} = i;
      // Aguarda um pequeno período de tempo para a estabilidade das saídas
      #10;
      // Imprime os valores de entrada e saída para cada combinação
      $display("Entrada: %b%b%b%b, Saída: %b%b%b", N3, N2, N1, N0, REMAINDER2, REMAINDER1, REMAINDER0);
    end
    // Encerra a simulação
    $finish;
  end

endmodule
