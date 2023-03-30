module helloworldfpga(

    input  wire a,
    input  wire b,
    input  wire c,
    
    output wire f,
    );
   assign a=0;
   assign b=0;
   assign c=0;
    
    always @(*)
    begin
    f=(b|!c)&(a|!c);
    end
    endmodule
