Public Module ReverseString
    Public Function Reverse(ByVal inputString As String) As String
        Dim revString As String
        revString = ""
        For i As Integer = inputString.Length()-1 To 0 Step -1
            revString = revString + inputString.Substring(i,1) 
        Next
        Return revString
        End Function
End Module
