using System;

public static class ErrorHandling
{
    public static void HandleErrorByThrowingException()
    {
        throw new Exception("You need to implement this function.");
    }

    public static int? HandleErrorByReturningNullableType(string input)
    {
        int i;
        if (Int32.TryParse(input, out i)) return i;
        else return null;
    }

    public static bool HandleErrorWithOutParam(string input, out int result)
    {

        if (Int32.TryParse(input, out result)) return true;
        return false;

    }

    public static void DisposableResourcesAreDisposedWhenExceptionIsThrown(IDisposable disposableObject)
    {

        using (disposableObject)
        {
            throw new Exception("Error");
        }

    }
}
