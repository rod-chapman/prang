package body P
  with SPARK_Mode => On,
       Refined_State => (State => (P1, P2, P3))
is
   M1  : constant := 30269;
   M1F : constant := 30269.0;
   R1  : constant := 171;
   A1  : constant := 177;
   B1  : constant := 2;

   M2  : constant := 30307;
   M2F : constant := 30307.0;
   R2  : constant := 172;
   A2  : constant := 176;
   B2  : constant := 35;

   M3  : constant := 30323;
   M3F : constant := 30323.0;
   R3  : constant := 170;
   A3  : constant := 178;
   B3  : constant := 63;

   subtype P1T is Short_Integer range 1 .. (M1 - 1);
   P1 : P1T := 1;

   subtype P2T is Short_Integer range 1 .. (M2 - 1);
   P2 : P2T := 2;

   subtype P3T is Short_Integer range 1 .. (M3 - 1);
   P3 : P3T := 3;


   procedure Prang (X : out Prang_Result)
     with Refined_Global => (In_Out => (P1, P2, P3))
   is
      Div1Q : constant Short_Integer := P1 / A1;
      Div1R : constant Short_Integer := P1 rem A1;
      Div2Q : constant Short_Integer := P2 / A2;
      Div2R : constant Short_Integer := P2 rem A2;
      Div3Q : constant Short_Integer := P3 / A3;
      Div3R : constant Short_Integer := P3 rem A3;

      subtype Aux1T is Long_Float range 0.0 .. Long_Float (P1T'Last) / M1F;
      Raux1 : Aux1T;

      subtype Aux2T is Long_Float range 0.0 .. Long_Float (P2T'Last) / M2F;
      Raux2 : Aux2T;

      subtype Aux3T is Long_Float range 0.0 .. Long_Float (P3T'Last) / M3F;
      Raux3 : Aux3T;

      subtype Temp_T is Short_Integer
        with Dynamic_Predicate => Temp_T /= 0;
      T  : Temp_T;

      subtype TXT is Long_Float range -Just_Below_One .. Just_Below_One;
      TX : TXT;

      function Remainder_1 (A : in Long_Float) return TXT
      is
      begin
         --  Proof false alarm here since GNATProve does not know enough
         --  about the mathematical properties of 'Remainder
         return Long_Float'Remainder (A, 1.0);
      end Remainder_1;

   begin
      T  := R1 * Div1R - B1 * Div1Q;
      P1 := T + (if T < 0 then M1 else 0);
      Raux1 := Long_Float (P1) / M1F;

      T  := R2 * Div2R - B2 * Div2Q;
      P2 := T + (if T < 0 then M2 else 0);
      Raux2 := Long_Float (P2) / M2F;

      T  := R3 * Div3R - B3 * Div3Q;
      P3 := T + (if T < 0 then M3 else 0);
      Raux3 := Long_Float (P3) / M3F;

      TX := Remainder_1 (Raux1 + Raux2 + Raux3);

      --  Clip upper-bound to Just_Below_One here to prevent TX + 1.0
      --  rounding up to exactly 1.0
      X := (if TX < 0.0 then Long_Float'Min (TX + 1.0, Just_Below_One) else TX);
   end Prang;


end P;
