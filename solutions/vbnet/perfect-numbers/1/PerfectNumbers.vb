Imports System
Imports System.Collections.Generic
Imports System.Linq

Public Module PerfectNumbers
    Enum Classification
        Perfect
        Abundant
        Deficient
    End Enum
    Public Function Classify(ByVal number As Integer) As Classification
        Dim s As Integer
        If number <= 0 Then
            Throw New ArgumentOutOfRangeException
        End If
        s = 0
        For i As Integer = 1 To number - 1
            If number Mod i = 0 Then
                s = s + i
            End If
        Next
        If s = number Then
            Return Classification.Perfect
        ElseIf s > number Then
            Return Classification.Abundant
        Else
            Return Classification.Deficient
        End If

    End Function
End Module
