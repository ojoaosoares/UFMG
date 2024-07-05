module mod_seven(A, B, C, D, OUT2, OUT1, OUT0);
  input A, B, C, D;
  
  // ABCD representa o número de 4 bits
  // OUT2 OUT 1 OUT 0 representa o resto de 3 bits
  
  output OUT2, OUT1, OUT0;
  reg OUT2, OUT1, OUT0;
  
  always @(*) begin
    OUT0 <= (!A && !B && D) || (!A && !C && D) || (A && !B && !D) || (A && !C && !D) || (A && B && C && D);
    OUT1 <= (A && !C && D) || (!B && C && !D) || (!A && C && !D) || (!A && !B && C);
    OUT2 <= (A && !B && C && D) || (B && !C) || (!A && B && !D);
  end
  
endmodule
