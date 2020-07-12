package P
  with SPARK_Mode     => On,
       Abstract_State => State,
       Initializes    => State
is

   procedure Prang (X : out Long_Float)
     with Global => (In_Out => State);

end P;
