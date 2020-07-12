package body P
  with SPARK_Mode => On,
       Refined_State => (State => S)
is
   type State_Type is record
      P1 : Short_Integer;
      P2 : Short_Integer;
      P3 : Short_Integer;
   end record;

   S : State_Type := (1, 2, 3);

   M1 : constant := 30269;
   R1 : constant := 171;
   A1 : constant := 177;
   B1 : constant := 2;

   M2 : constant := 30307;
   R2 : constant := 172;
   A2 : constant := 176;
   B2 : constant := 35;

   M3 : constant := 30323;
   R3 : constant := 170;
   A3 : constant := 178;
   B3 : constant := 63;


   procedure Prang (X : out Long_Float)
   is
      Div1Q : constant Integer := Integer (S.P1) / Integer (A1);
      Div1R : constant Integer := Integer (S.P1) rem Integer (A1);
      Div2Q : constant Integer := Integer (S.P2) / Integer (A2);
      Div2R : constant Integer := Integer (S.P2) rem Integer (A2);
      Div3Q : constant Integer := Integer (S.P3) / Integer (A3);
      Div3R : constant Integer := Integer (S.P3) rem Integer (A3);

      Raux1,
      Raux2,
      Raux3 : Long_Float;
   begin
      S := (P1 => R1 * Short_Integer (Div1R) - B1 * Short_Integer (Div1Q),
            P2 => R2 * Short_Integer (Div2R) - B2 * Short_Integer (Div2Q),
            P3 => R3 * Short_Integer (Div3R) - B3 * Short_Integer (Div3Q));

      S.P1 := S.P1 + (if S.P1 < 0 then M1 else 0);
      S.P2 := S.P2 + (if S.P2 < 0 then M2 else 0);
      S.P3 := S.P3 + (if S.P3 < 0 then M3 else 0);

      Raux1 := Long_Float (S.P1) / Long_Float (M1);
      Raux2 := Long_Float (S.P2) / Long_Float (M2);
      Raux3 := Long_Float (S.P3) / Long_Float (M3);

      X := Long_Float'Remainder (Raux1 + Raux2 + Raux3, 1.0);
      X := (if X < 0.0 then X + 1.0 else X);
   end Prang;


end P;
