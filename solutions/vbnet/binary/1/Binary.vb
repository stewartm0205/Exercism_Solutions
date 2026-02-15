Public Class Binary
    Public binary As String
    Public Sub New(newbinary As String)
        binary = newbinary
    End Sub

    Public Function ToDecimal() As Integer
        Dim dec, mul As Integer
        mul = 1
        dec = 0
        For i As Integer = binary.Length() - 1 To 0 Step -1
            If binary.Substring(i, 1) = "1" Then
                dec = dec + mul
            ElseIf binary.Substring(i, 1) <> "0" Then
                Return 0
            End If
            mul = mul * 2
        Next
        Return dec
    End Function
End Class