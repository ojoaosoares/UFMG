module contador_sequencial(
    input wire clk,        // Sinal de clock
    input wire reset,      // Sinal de reset
    output reg [3:0] count // Saída de 4 bits
);
  // As variaveis são inicializadas com o valor0 (0000)
  initial begin
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    count[3] = 0;
  end
    

    // Bloco always sensível ao clock
  always @(posedge clk) begin
        if (reset) begin
            count <= 4'b0000; // Resetar o contador para 0 quando o reset estiver ativo
        end else begin // Os valores são atualizados quando o clock está ativo
            count[0] <= !count[0];
            count[1] <= (count[1] && !count[0]) || (!count[3] && !count[1] && count[0]);
            count[2] <= (count[2] && !count[1]) || (count[2] && !count[0]) || (!count[2] && count[1] && count[0]);
            count[3] <= (count[3] && !count[0]) || (count[2] && count[1] && count[0]);
        end
    end

endmodule
