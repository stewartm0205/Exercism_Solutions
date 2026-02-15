Public Class Allergies

    Dim allergies As Integer

    Sub New(allergiesIn As Integer)
        allergies = allergiesIn
    End Sub
    Function AllergicTo(ByVal substance As String) As Boolean
        Dim alls As List(Of String)
        alls = List()
        If alls.Contains(substance) Then
            Return True
        Else
            Return False
        End If
    End Function
    Function List() As List(Of String)
        Dim l As List(Of String) = New List(Of String)()
        'Dim substance As List(Of String) = New List(Of String)({"cats", "pollen", "chocolate", "tomatoes", "strawberries", "shellfish", "peanuts", "egg"})
        Dim substance As List(Of String) = New List(Of String)({"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"})
        Dim a As Integer
        a = allergies
        For i As Integer = 0 To 7
            If a Mod 2 = 1 Then
                l.Add(substance(i))
            End If
            a = Math.Floor(a / 2)
        Next
        Return l
    End Function
End Class