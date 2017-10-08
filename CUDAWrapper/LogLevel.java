package CUDAWrapper;

/**
 * The log levels which may be used to control the internal
 * logging of the CUDAWrapper libraries
 */
public enum LogLevel
{
    /**
     * Never print anything
     */
    LOG_QUIET,

    /**
     * Only print error messages
     */
    LOG_ERROR,

    /**
     * Print warnings
     */
    LOG_WARNING,

    /**
     * Print info messages
     */
    LOG_INFO,

    /**
     * Print debug information
     */
    LOG_DEBUG,

    /**
     * Trace function calls
     */
    LOG_TRACE,

    /**
     * Print fine-grained debug information
     */
    LOG_DEBUGTRACE
}
