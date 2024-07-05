module tb_contador_sequencial;

    // Declaração de sinais de teste
    reg clk;
    reg reset;
    wire [3:0] count;

    // Instanciar o módulo a ser testado
    contador_sequencial uut (
        .clk(clk),
        .reset(reset),
        .count(count)
    );

    // Gerar o sinal de clock
    always #10 clk = ~clk; // Período de clock de 10 unidades de tempo

    initial begin
        // Inicializar sinais
        clk = 0;
      reset = 0; // Iniciar com reset desativado(0)
      
      
      	#100; // Apos 5 segundos: 10 * 2 * 5 (2 * tempo do clock * segundos)
        reset = 1;

        
        #19; // O sinal de reset fica ativo por exatamente 19 unidades do tempo, o que garante que a borda de subida pegara o sinal
        reset = 0;

      	// O programa dura por mais 12 segundos: 10*2*12 (2 * tempo do clock * segundos)
        #240; 

        $finish;
    end

    initial begin
        // Monitorar os sinais durante a simulação
        $monitor("Time: %0t, clk: %b, reset: %b, count: %b",
                 $time, clk, reset, count);
    end
  
  	initial begin
        $dumpfile("dump.vcd"); // Nome do arquivo VCD
        $dumpvars(0, tb_contador_sequencial); // Registrar todas as variáveis do testbench
    end

endmodule
