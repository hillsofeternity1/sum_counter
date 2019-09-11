#define floor(x) ((x*2.0-0.5)shr 1)
Dim last As Long
Dim As Long num, digit, sum, start, end_
start = 0
end_ = 1000000

repeat:
  If start < end_ Then
    num = end_
    Do
      If num = 0 Then Exit Do
      digit = num Mod 10
      sum = sum + digit
      num = floor(num / 10)
    Loop
    end_ = end_ - 1
    Goto repeat
  End If
Print sum

