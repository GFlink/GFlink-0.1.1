
package CUDAWrapper.runtime;

/**
 * Surface format modes
 *
 * @see surfaceReference
 */
public class cudaSurfaceFormatMode
{
    public static final int cudaFormatModeForced = 0;
    public static final int cudaFormatModeAuto = 1;

    /**
     * Returns the String identifying the given cudaSurfaceFormatMode
     *
     * @param m The cudaSurfaceFormatMode
     * @return The String identifying the given cudaSurfaceFormatMode
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaFormatModeForced: return "cudaFormatModeForced";
            case cudaFormatModeAuto: return "cudaFormatModeAuto";
        }
        return "INVALID cudaSurfaceFormatMode: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaSurfaceFormatMode()
    {
    }

};
