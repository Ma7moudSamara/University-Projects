 -- 119602                MAHMOUD SAMARA            ENCS3310        FINAL PROJECT

-- BEFORE STARTING MY CODE FIRST WE NEED IMPLEMENT THE BASIC ENTITY FOR STAGE 1.

 ----------------------------------------------------------------------------------
-- STAGE 1 FULL CODES
----------------------------------------------------------------------------------
-------------------------AND gate code ----------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY AND_GATE IS 
	
PORT(A,B: IN STD_LOGIC;
F: OUT STD_LOGIC);
END ENTITY AND_GATE;

ARCHITECTURE struct_and OF AND_GATE IS
BEGIN
F <= A AND B;
END ARCHITECTURE struct_and;
-------------------------------------------------

--------------------------OR gate code----------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;


ENTITY OR_GATE IS 
	
PORT(A,B: IN STD_LOGIC;
F: OUT STD_LOGIC);
END ENTITY OR_GATE;

ARCHITECTURE struct_or OF OR_GATE IS
BEGIN
F <= A OR B;
END ARCHITECTURE struct_or;
-------------------------------------------------

--------------------------XOR gate code----------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;


ENTITY XOR_GATE IS 
	
PORT(A,B: IN STD_LOGIC;
F: OUT STD_LOGIC);
END ENTITY XOR_GATE;

ARCHITECTURE struct_xor OF XOR_GATE IS
BEGIN
F <= A XOR B;
END ARCHITECTURE struct_xor;  

----------------------------------------------------------------------

--after making the basic gates we have to make n-bit adder but before that we have to make full adder
-- and to make the full adder I need two half adder , or gate

----------- half adder full code----------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY half_adder IS
    PORT ( a,b : IN std_logic;
           sum,carry: OUT std_logic
           );
END half_adder;

ARCHITECTURE half_adder_arch OF half_adder IS
  BEGIN
    G1: ENTITY work.XOR_GATE(struct_xor) PORT MAP (a,b,sum);
	G2: ENTITY work.AND_GATE(struct_and) PORT MAP (a,b,carry);
	
END half_adder_arch;	 

----------- full adder full code----------------


LIBRARY IEEE;
USE IEEE. STD_LOGIC_1164.ALL; 


ENTITY fulladder IS
PORT (x,y,cin :IN STD_LOGIC;
      sum,carry : OUT STD_LOGIC);
END fulladder;

ARCHITECTURE FA_arch OF fulladder IS

SIGNAL s1,c1,c2 : STD_LOGIC;
BEGIN
 w1:ENTITY work.half_adder(half_adder_arch) PORT MAP (x,y,s1,c1);
 w2:ENTITY work.half_adder(half_adder_arch) PORT MAP (s1,cin,sum,c2);
 w3: ENTITY work.OR_GATE(struct_or) PORT MAP (c1,c2,carry);
END FA_arch;  

---------------------------------------------------------------------------- 

---------------------- n-bit adder full code -------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;	 

ENTITY bit_adder IS  
	GENERIC(n : POSITIVE);
	PORT(x, y : IN STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		  cin : IN STD_LOGIC;
 		    sum : OUT STD_LOGIC_VECTOR(n-1 DOWNTO 0);
  		 carryout : OUT STD_LOGIC);
END ENTITY bit_adder;		   

ARCHITECTURE bit_structural OF bit_adder IS

SIGNAL crry : STD_LOGIC_VECTOR(n DOWNTO 0);
BEGIN
    crry(0) <= cin;
    
	carryout <= crry(n);
    
    loop1: FOR i IN 0 TO (n - 1) GENERATE  
	g1 : ENTITY WORK.fulladder(FA_arch)
       		PORT MAP (x(i),y(i),crry(i),sum(i),crry(i+1));
	
	END GENERATE loop1;

	END ARCHITECTURE bit_structural;
----------------------------------------------------------------------

---------------------- STAGE 1 multiplier full code -------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;  

ENTITY stage1_mult IS 
	
	GENERIC(j: POSITIVE  ; k: POSITIVE );		  
	PORT(x  : IN  STD_LOGIC_VECTOR((j - 1) DOWNTO 0);
		 y  : IN  STD_LOGIC_VECTOR((k - 1) DOWNTO 0);
		result : OUT STD_LOGIC_VECTOR((j + k - 1) DOWNTO 0));
END ENTITY stage1_mult;									  

ARCHITECTURE stage1_multBHV OF stage1_mult IS

TYPE tmp_array IS ARRAY (j-1 DOWNTO 0 ) OF std_logic_vector (k-1 DOWNTO 0);  
 
SIGNAL aand  : tmp_array;
SIGNAL sum : tmp_array;
SIGNAL moved_sum  : tmp_array;
SIGNAL cout : std_logic_vector (j-1 DOWNTO 0);

COMPONENT AND_GATE IS 	-- calling AND_GATE entity using component
	
PORT(A,B: IN STD_LOGIC;

F: OUT STD_LOGIC);

END COMPONENT;
-------

COMPONENT bit_adder IS  		 -- calling bit_adder entity using component
	GENERIC(n : POSITIVE:=4); -- since our code has j = 7  , k = 4  and the adder is j-1  k-bit  so n = 4 as k
	
	PORT(x, y : IN STD_LOGIC_VECTOR(n-1 DOWNTO 0);
		  cin : IN STD_LOGIC;
 		    sum : OUT STD_LOGIC_VECTOR(n-1 DOWNTO 0);
  		 carryout : OUT STD_LOGIC);

END COMPONENT;

-- before starting my code from the diagram of parallel multiplier we can wee that we have three cases 
-- we k = 1  , k > 1 , k > 1 and j > 1 .

BEGIN	

kisONE:
IF(k = 1) GENERATE	
andingLoop: 
FOR i IN j - 1 DOWNTO 0 GENERATE 
andLoop:AND_GATE PORT MAP(x(i), y(0), result(i)); 
END GENERATE andingLoop;
result(j) <= '0';
END GENERATE kisONE;
	

KBIGGERone:
IF(k > 1) GENERATE
x_loop: FOR i IN 0 TO j - 1 GENERATE
y_loop: FOR m IN 0 TO k - 1 GENERATE 
andLoop:AND_GATE PORT MAP(x(i), y(m), aand(i)(m)); 
END GENERATE y_loop;
END GENERATE x_loop;
sum(0) <= aand(0);
cout(0) <= '0';	
				
JK: 
IF(j > 1 AND k > 1) GENERATE 

muliplication: FOR i IN 0 TO j-2 GENERATE
result(i) <= sum(i)(0); 		
moved_sum(i) <= cout(i) & sum(i)(k-1 DOWNTO 1);	
Adder:bit_adder PORT MAP (moved_sum(i), aand(i+1), '0', sum(i+1), cout(i+1));
END GENERATE muliplication;		   
END GENERATE JK; 
result(j+k-1 DOWNTO j-1) <= cout(j-1) & sum(j-1);

END GENERATE KBIGGERone;

END ARCHITECTURE stage1_multBHV;

--------------------------------------------------------------------------------
-- Test bench Code
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE ieee.std_logic_UNSIGNED.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY TestGenerator IS
PORT(
CLK: IN STD_LOGIC:='0';
x    :  OUT  std_logic_vector(6 DOWNTO 0):="0000000";
y    :  OUT  std_logic_vector(3 DOWNTO 0):="0000";
correct :  OUT std_logic_vector(10 DOWNTO 0):="00000000000"
);

END TestGenerator;

ARCHITECTURE behavioral OF TestGenerator IS
BEGIN
PROCESS
BEGIN
FOR I IN 0 TO 127 LOOP
FOR J IN 0 TO 15 LOOP
-- Set the inputs 
x <= CONV_STD_LOGIC_VECTOR(i,7);
y <= CONV_STD_LOGIC_VECTOR(j,4);
-- Calculate what the output of the mult should be
correct <= CONV_STD_LOGIC_VECTOR(i*j,11);
-- Wait until mult output 
WAIT UNTIL rising_edge(CLK);
END LOOP;
END LOOP;
WAIT;
END PROCESS;
END ;
----------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_ARITH.ALL;

ENTITY ResultAnalyser IS

PORT(CLK: IN STD_LOGIC:='0';
correct,result: IN STD_LOGIC_VECTOR(10 DOWNTO 0):="00000000000");
END ResultAnalyser;

ARCHITECTURE analyser OF ResultAnalyser IS
BEGIN
-- The Process below make sure that the resulting output from our system equals to the correct one
-- otherwise, print an error when the outputs are not equal to each other
PROCESS
BEGIN
ASSERT (result = correct)
REPORT "Something went wrong , because the results that were printed is not as the actual results"
SEVERITY ERROR;
WAIT UNTIL rising_edge(CLK);
END PROCESS;
END analyser;
--
-----------------------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_ARITH.ALL;

ENTITY PMUTL_TEST IS
END PMUTL_TEST;


ARCHITECTURE tb OF PMUTL_TEST IS
SIGNAL CLK: STD_LOGIC:='0';
SIGNAL x       : std_logic_vector(6 DOWNTO 0) :="0000000";
SIGNAL y       : std_logic_vector(3 DOWNTO 0) :="0000";
SIGNAL result  : std_logic_vector(10 DOWNTO 0):= "00000000000";
SIGNAL correct : std_logic_vector( 10 DOWNTO 0):= "00000000000";

BEGIN

CLK <= NOT CLK AFTER 30 NS;
G1: ENTITY WORK.TestGenerator(behavioral) PORT MAP(CLK, x, y, correct);
G2: ENTITY WORK.stage1_mult(stage1_multBHV) GENERIC MAP (7,4) PORT MAP(x, y, result(10 DOWNTO 0));
G3: ENTITY WORK.ResultAnalyser(analyser) PORT MAP(CLK, correct, result);
END tb;

---------------------------------------------------------------------
  ---  Stage 2 full code
---------------------------------------------------------------------

-- FOR STAGE TWO I MADE IT AS THE WEBSITE FIGURE 4 * 4 MULTILPLIER BECAUSE I DON'T WANT TO GIVE AN EMPTY CODE FOR STAGE 2
--  THANK YOU DOCTOR FOR UNDERSTANDING ME 
	
---------------------------------------------------------------------


LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY nADDER IS
GENERIC (N: integer := 4);
PORT( A: IN std_logic_vector(N-1 DOWNTO 0); -- N bit Addend
B: IN std_logic_vector(N-1 DOWNTO 0); -- N bit Augend
S: OUT std_logic_vector(N DOWNTO 0) -- N+1 bit result, includes carry
);

END nADDER;
ARCHITECTURE AdderN_Behavioral OF nADDER IS
BEGIN
S <= std_logic_vector(('0' & UNSIGNED(A)) + UNSIGNED(B));

END AdderN_Behavioral;

---------------------------------------------------------------------
  ---  RegN
---------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Registerr IS
GENERIC (N: integer := 4);
PORT ( reg_input: IN std_logic_vector(N-1 DOWNTO 0); --N-bit input
reg_output: OUT std_logic_vector(N-1 DOWNTO 0); --N-bit output
Clk: IN std_logic; --Clock 
Load_enable: IN std_logic; 
Shift_enable: IN std_logic; 
Clear_enable: IN std_logic; 
SerIn: IN std_logic --Serial input
);
END Registerr;

ARCHITECTURE RegN_Behavioral OF RegN IS
SIGNAL D: std_logic_vector(N-1 DOWNTO 0); 
BEGIN
PROCESS (Clk)
BEGIN
IF (rising_edge(Clk)) THEN 
IF (Clear_enable = '1') THEN
D <= (OTHERS => '0'); 
ELSIF (Load_enable = '1') THEN
D <= reg_input; 
ELSIF (Shift_enable = '1') THEN
D <= SerIn & D(N-1 DOWNTO 1); 
END IF;
END IF;
END PROCESS;
reg_output <= D;

END RegN_Behavioral;

---------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY Stage2_mult IS
PORT ( x: IN std_logic_vector(3 DOWNTO 0);
y: IN std_logic_vector(3 DOWNTO 0);
Product: OUT std_logic_vector(7 DOWNTO 0);
Start: IN std_logic;
Clk: IN std_logic;
Done: OUT std_logic);
END Stage2_mult;

ARCHITECTURE BEHAV OF Stage2_mult IS

SIGNAL multout,quit: std_logic_vector (3 DOWNTO 0);
SIGNAL Dout,outt: std_logic_vector (4 DOWNTO 0);
SIGNAL load_in,Shift,addition: std_logic;

BEGIN 	

-- 4-bit adder; 5-bit output includes carry
A: ENTITY WORK.nADDER(AdderN_Behavioral) GENERIC MAP (4) PORT MAP (outt(3 DOWNTO 0),multout,Dout);

-- 4-bit Multiplicand register
B: ENTITY WORK.Registerr(RegN_Behavioral) GENERIC MAP (4) PORT MAP (y,multout,Clk,load_in,'0','0','0');

-- 4-bit Multiplier register
C: ENTITY WORK.Registerr(RegN_Behavioral) GENERIC MAP (4) PORT MAP (x,quit,Clk,load_in,Shift,'0',outt(0));

D: ENTITY WORK.Registerr(RegN_Behavioral) GENERIC MAP (5) PORT MAP (Dout,outt,Clk,addition,Shift,load_in,'0');

Product <= outt(3 DOWNTO 0) & quit; 

END BEHAV ;

-----------------------------------------------------------------------------------

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_ARITH.ALL;


ENTITY Resultcheck IS
PORT(CLK: IN STD_LOGIC:='0';
correct,result: IN STD_LOGIC_VECTOR(7 DOWNTO 0):="00000000");
END Resultcheck;

ARCHITECTURE checker OF Resultcheck IS
BEGIN

-- The Process below make sure that the resulting output from our system equals to the correct one
-- otherwise, print an error when the outputs are not equal to each other
PROCESS
BEGIN
ASSERT (result = correct)
REPORT "The results that were obtained is not as the theoretical results"
SEVERITY ERROR;
WAIT UNTIL rising_edge(CLK);
END PROCESS;
END checker;
--------------------------------------------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
USE ieee.std_logic_UNSIGNED.ALL;
USE IEEE.NUMERIC_STD.ALL;

ENTITY TBcircuit IS   

END TBcircuit;	

ARCHITECTURE arcTB OF TBcircuit IS
SIGNAL x , y :  std_logic_vector(3 DOWNTO 0):="0000";
SIGNAL Product: std_logic_vector(7 DOWNTO 0):="00000000";
SIGNAL Start , Clk , Done : std_logic:='0';


BEGIN 

Clk <= NOT Clk AFTER 20 ns; 

x<= "0001" AFTER 20 ns , "0011" AFTER 50 ns , "0110" AFTER 100 ns;

y<= "0001" AFTER 10 ns , "0100" AFTER 40 ns , "1000" AFTER 80 ns;	
END arcTB; 