package P
  with SPARK_Mode     => On,
       Abstract_State => State,
       Initializes    => State
is
   Just_Below_One  : constant Long_Float := Long_Float'Adjacent (1.0, 0.0);

   subtype Prang_Result is Long_Float range 0.0 .. Just_Below_One;

   procedure Prang (X : out Prang_Result)
     with Global => (In_Out => State);

end P;
