Imports System.Text.RegularExpressions
Public Class PhoneNumber
    Public Shared Function Clean(ByVal phoneNumber As String) As String

        phoneNumber = Regex.Replace(phoneNumber, "[ .()+-]+", "")
        Dim allnum As Regex = New Regex("^\d+$")
        Dim isnumeric As Match = allnum.Match(phoneNumber)
        If Not isnumeric.Success Then
            Throw New ArgumentException
        End If
        If phoneNumber.Length() > 11 Then
            Throw New ArgumentException
        End If
        If phoneNumber.Length() = 11 Then
            If phoneNumber.Substring(0, 1) <> "1" Then
                Throw New ArgumentException
            End If
            phoneNumber = phoneNumber.Substring(1, 10)
        End If
        If phoneNumber.Substring(0, 1) = "0" Or phoneNumber.Substring(0, 1) = "1" Then
            Throw New ArgumentException
        End If
        If phoneNumber.Substring(3, 1) = "0" Or phoneNumber.Substring(3, 1) = "1" Then
            Throw New ArgumentException
        End If
        Return phoneNumber
        'Throw New NotImplementedException("You need to implement this function")
    End Function
End Class
