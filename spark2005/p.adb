package body P
--# own State is S;
is
   type State_Type is record
      P1 : Short_Integer;
      P2 : Short_Integer;
      P3 : Short_Integer;
   end record;

   S : State_Type := State_Type'(1, 2, 3);

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
   --# global in out S;
   --# derives X, S from S;
   is
      Div1Q,
      Div1R,
      Div2Q,
      Div2R,
      Div3Q,
      Div3R : Integer;

      Raux1,
      Raux2,
      Raux3 : Long_Float;
   begin
      Div1Q := Integer (S.P1) / Integer (A1);
      Div1R := Integer (S.P1) rem Integer (A1);
      Div2Q := Integer (S.P2) / Integer (A2);
      Div2R := Integer (S.P2) rem Integer (A2);
      Div3Q := Integer (S.P3) / Integer (A3);
      Div3R := Integer (S.P3) rem Integer (A3);

      S := State_Type'(P1 => R1 * Short_Integer (Div1R) - B1 * Short_Integer (Div1Q),
                       P2 => R2 * Short_Integer (Div2R) - B2 * Short_Integer (Div2Q),
                       P3 => R3 * Short_Integer (Div3R) - B3 * Short_Integer (Div3Q));

      if S.P1 < 0 then
         S.P1 := S.P1 + M1;
      end if;

      if S.P2 < 0 then
         S.P2 := S.P2 + M2;
      end if;

      if S.P3 < 0 then
         S.P3 := S.P3 + M3;
      end if;

      Raux1 := Long_Float (S.P1) / Long_Float (M1);
      Raux2 := Long_Float (S.P2) / Long_Float (M2);
      Raux3 := Long_Float (S.P3) / Long_Float (M3);

      X := Long_Float'Remainder ((Raux1 + Raux2) + Raux3, 1.0);

      if X < 0.0 then
         X := X + 1.0;
      end if;

   end Prang;


end P;
