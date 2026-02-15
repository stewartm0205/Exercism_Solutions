Public Module Hamming
    Public Function Distance(ByVal firstStrand As String, ByVal secondStrand As String) As Integer
        Dim dist As Integer
        If firstStrand.Length() <> secondStrand.Length() Then
            Throw New ArgumentException
        End If
        dist = 0
        For i As Integer = 0 To firstStrand.Length() - 1
            If firstStrand.Substring(i, 1) <> secondStrand.Substring(i, 1) Then
                dist = dist + 1
            End If
        Next
        Return dist
    End Function
End Module