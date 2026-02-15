Imports System

Public Module CollatzConjecture
    Public Function Steps(ByVal number As Integer) As Integer
        Dim s As Integer
        If number <= 0 Then
            Throw New ArgumentOutOfRangeException
        End If
        s = 0
        While number > 1
            s = s + 1
            If number Mod 2 = 0 Then
                number = number / 2
            Else
                number = 3 * number + 1
            End If
        End While
        Return s
    End Function
End Module