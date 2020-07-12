with P;
with Ada.Text_IO; use Ada.Text_IO;
procedure Main
is
   X : Long_Float;
   package LFIO is new Float_IO (Long_Float);
begin
   for I in Positive range 1 .. 80 loop
      P.Prang (X);
      LFIO.Put (Standard_Output, X, 1, 6, 0);
      New_Line;
   end loop;
end Main;
