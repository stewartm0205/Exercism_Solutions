using System;

static class LogLine
{
    public static string Message(string logLine)
    {
        string message = logLine.Substring(logLine.IndexOf(":")+2).Trim();
        return message;
        //throw new NotImplementedException("Please implement the (static) LogLine.Message() method");
    }

    public static string LogLevel(string logLine)
    {
        string logLevel = logLine.Substring(1,logLine.IndexOf("]:")-1);
        return logLevel.ToLower();
        //throw new NotImplementedException("Please implement the (static) LogLine.LogLevel() method");
    }

    public static string Reformat(string logLine)
    {
        string message = logLine.Substring(logLine.IndexOf(":")+2).Trim();
              string logLevel = logLine.Substring(1,logLine.IndexOf("]:")-1).ToLower();
        return message + " ("+logLevel+")";
        //throw new NotImplementedException("Please implement the (static) LogLine.Reformat() method");
    }
}
