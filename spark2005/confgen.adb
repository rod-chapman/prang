-------------------------------------------------------------------------------
-- (C) Altran UK Limited
-------------------------------------------------------------------------------
--
-- The SPARK toolset is free software; you can redistribute it and/or modify it
-- under terms of the GNU General Public License as published by the Free
-- Software Foundation; either version 3, or (at your option) any later
-- version. The SPARK toolset is distributed in the hope that it will be
-- useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
-- Public License for more details. You should have received a copy of the GNU
-- General Public License distributed with the SPARK toolset; see file
-- COPYING3. If not, go to http://www.gnu.org/licenses for a complete copy of
-- the license.
--
--=============================================================================


--  This utility is intended to generate a target configuration file for use
--  with the SPARK Examiner.

--  *** IMPORTANT WARNING ***

--  If you are using a cross-compiler, please note that this program
--  must be compiled for and run on the target, rather than the host,
--  in order to generate valid output.

--  If you are using an embedded target which does not support Text_IO,
--  but does have another mechanism for string output, change the
--  following 'with' clause and update the 'renames' clause in the
--  definition of package Output_Method below.

with Text_IO;
with System;

procedure Confgen is

   package Output_Method renames Text_IO;
   use Output_Method;

   type T is range System.Min_Int .. System.Max_Int;
   type Tmod is mod System.Max_Binary_Modulus;
   type Tfloat is digits System.Max_Base_Digits range -1.0 .. 1.0;

begin

   -------------------------
   -- Output header block --
   -------------------------

   Put_Line ("-- Auto-generated SPARK target configuration file");
   Put_Line ("-- Target claims to be '" &
             System.Name'Image (System.System_Name) & "'");
   New_Line;

   ----------------------
   -- Package Standard --
   ----------------------

   Put_Line ("package Standard is");

   --  type Integer and Float are mandatory for SPARK95

   Put_Line ("   type Integer is range " &
             Integer'Image (Integer'First) & " .. " &
             Integer'Image (Integer'Last) & ";");

   Put_Line ("   type Float is digits " &
             Integer'Image (Float'Digits) & " range " &
             Float'Image (Float'First) & " .. " &
             Float'Image (Float'Last) & ";");

   --  Uncomment any of the following that are supported by your
   --  compiler and target

   --  Optional signed integer types

   --  Put_Line ("   type Short_Short_Integer is range " &
   --            Short_Short_Integer'Image (Short_Short_Integer'First) &
   --            " .. " &
   --            Short_Short_Integer'Image (Short_Short_Integer'Last) & ";");
   Put_Line ("   type Short_Integer is range " &
             Short_Integer'Image (Short_Integer'First) & " .. " &
             Short_Integer'Image (Short_Integer'Last) & ";");
   --  Put_Line ("   type Long_Integer is range " &
   --            Long_Integer'Image (Long_Integer'First) & " .. " &
   --            Long_Integer'Image (Long_Integer'Last) & ";");
   --  Put_Line ("   type Long_Long_Integer is range " &
   --            Long_Long_Integer'Image (Long_Long_Integer'First) & " .. " &
   --            Long_Long_Integer'Image (Long_Long_Integer'Last) & ";");

   --  Optional floating point types

   --  Put_Line ("   type Short_Short_Float is digits " &
   --            Integer'Image (Short_Short_Float'Digits) & " range " &
   --            Short_Short_Float'Image (Short_Short_Float'First) & " .. " &
   --            Short_Short_Float'Image (Short_Short_Float'Last) & ";");
   --  Put_Line ("   type Short_Float is digits " &
   --            Integer'Image (Short_Float'Digits) & " range " &
   --            Short_Float'Image (Short_Float'First) & " .. " &
   --            Short_Float'Image (Short_Float'Last) & ";");
   Put_Line ("   type Long_Float is digits " &
             Integer'Image (Long_Float'Digits) & " range " &
             Long_Float'Image (Long_Float'First) & " .. " &
             Long_Float'Image (Long_Float'Last) & ";");
   --  Put_Line ("   type Long_Long_Float is digits " &
   --            Integer'Image (Long_Long_Float'Digits) & " range " &
   --            Long_Long_Float'Image (Long_Long_Float'First) & " .. " &
   --            Long_Long_Float'Image (Long_Long_Float'Last) & ";");

   Put_Line ("end Standard;");
   New_Line;

   --------------------
   -- Package System --
   --------------------

   Put_Line ("package System is");

   --  The definition of type System.Address is optional; if it is specified,
   --  it must be private.

   Put_Line ("   type Address is private;");
   Put_Line ("   Min_Int : constant := " & T'Image (System.Min_Int) & ";");
   Put_Line ("   Max_Int : constant := " & T'Image (System.Max_Int) & ";");
   Put_Line ("   Max_Binary_Modulus : constant := " &
             Tmod'Image (Tmod'Last) & " + 1;");
   Put_Line ("   Max_Digits : constant := " &
             T'Image (System.Max_Digits) & ";");
   Put_Line ("   Max_Base_Digits : constant := " &
             T'Image (System.Max_Base_Digits) & ";");
   Put_Line ("   Max_Mantissa : constant := " &
             T'Image (System.Max_Mantissa) & ";");
   Put_Line ("   Storage_Unit : constant := " &
             T'Image (System.Storage_Unit) & ";");
   Put_Line ("   Word_Size : constant := " &
             T'Image (System.Word_Size) & ";");
   Put_Line ("   Fine_Delta : constant := " &
             Tfloat'Image (System.Fine_Delta) & ";");
   Put_Line ("   subtype Any_Priority is Integer range " &
             Integer'Image (System.Any_Priority'First) & " .. " &
             Integer'Image (System.Any_Priority'Last) & ";");
   Put_Line ("   subtype Priority is Any_Priority range " &
             Integer'Image (System.Priority'First) & " .. " &
             Integer'Image (System.Priority'Last) & ";");
   Put_Line ("   subtype Interrupt_Priority is Any_Priority range " &
             Integer'Image (System.Interrupt_Priority'First) & " .. " &
             Integer'Image (System.Interrupt_Priority'Last) & ";");

   Put      ("   Default_Bit_Order : constant Bit_Order := ");
   case System.Default_Bit_Order is
      when System.Low_Order_First =>
         Put ("Low");
      when System.High_Order_First =>
         Put ("High");
   end case;
   Put_Line ("_Order_First;");

   Put_Line ("end System;");

end Confgen;
