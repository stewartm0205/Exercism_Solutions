Public Class Bob

    Public Function Hey(statement As String) As String
        statement = statement.Trim()
        If statement.IndexOf("?") = statement.Length() - 1 And
            statement.ToUpper() = statement And
            hasLetter(statement) Then
            Return "Calm down, I know what I'm doing!"
        ElseIf statement.Length() = 0 Then
            Return "Fine. Be that way!"
        ElseIf statement.IndexOf("?") = statement.Length() - 1 Then
            Return "Sure."
        ElseIf statement.ToUpper() = statement And hasLetter(statement) Then
            Return "Whoa, chill out!"
        Else
            Return "Whatever."
        End If
    End Function
    Public Function hasLetter(statement As String) As Boolean
        For i As Integer = 0 To statement.Length() - 1
            If statement.ToUpper().Substring(i, 1) >= "A" And statement.ToUpper().Substring(i, 1) <= "Z" Then
                Return True
            End If
        Next
        Return False
    End Function
End Class