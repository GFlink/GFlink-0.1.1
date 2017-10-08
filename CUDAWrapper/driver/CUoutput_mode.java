
package CUDAWrapper.driver;

/**
 * Profiler Output Modes.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.
 *
 * @see CUDAWrapperDriver#cuProfilerInitialize
 */
public class CUoutput_mode
{
    /**
     * Output mode Key-Value pair format.
     */
    public static final int CU_OUT_KEY_VALUE_PAIR  = 0x00;

    /**
     * Output mode Comma separated values format.
     */
    public static final int CU_OUT_CSV             = 0x01;


    /**
     * Returns the String identifying the given CUoutput_mode
     *
     * @param n The CUoutput_mode
     * @return The String identifying the given CUoutput_mode
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_OUT_KEY_VALUE_PAIR: return "CU_OUT_KEY_VALUE_PAIR";
            case CU_OUT_CSV: return "CU_OUT_CSV";
        }
        return "INVALID CUoutput_mode: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUoutput_mode()
    {
    }

}
