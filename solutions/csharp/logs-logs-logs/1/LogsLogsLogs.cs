using System;

// TODO: define the 'LogLevel' enum
enum LogLevel {
    Trace=1,
    Debug=2,
    Info=4,
    Warning=5,
    Error=6,
    Fatal=42,
    Unknown = 0
}

static class LogLine
{
    public static LogLevel ParseLogLevel(string logLine)
    {
        LogLevel ll;
        switch (logLine.Substring(1,3)) {
            case "TRC" : return LogLevel.Trace;
            case "DBG" : return LogLevel.Debug;
            case "INF" : return LogLevel.Info;
            case "WRN" : return LogLevel.Warning;
            case "ERR" : return LogLevel.Error;
            case "FTL" : return LogLevel.Fatal;
            default : return LogLevel.Unknown;
        }
        //throw new NotImplementedException("Please implement the (static) LogLine.ParseLogLevel() method");
    }

    public static string OutputForShortLog(LogLevel logLevel, string message)
    {
        return ((int)logLevel).ToString() + ":" + message;
        //throw new NotImplementedException("Please implement the (static) LogLine.OutputForShortLog() method");
    }
}
