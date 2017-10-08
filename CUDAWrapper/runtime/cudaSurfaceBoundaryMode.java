

package CUDAWrapper.runtime;

/**
 * Surface boundary modes
 *
 * @see surfaceReference
 */
public class cudaSurfaceBoundaryMode
{
    public static final int cudaBoundaryModeZero = 0;
    public static final int cudaBoundaryModeClamp = 1;
    public static final int cudaBoundaryModeTrap = 2;

    /**
     * Returns the String identifying the given cudaSurfaceBoundaryMode
     *
     * @param m The cudaSurfaceBoundaryMode
     * @return The String identifying the given cudaSurfaceBoundaryMode
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaBoundaryModeZero: return "cudaBoundaryModeZero";
            case cudaBoundaryModeClamp: return "cudaBoundaryModeClamp";
            case cudaBoundaryModeTrap: return "cudaBoundaryModeTrap";
        }
        return "INVALID cudaSurfaceBoundaryMode: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaSurfaceBoundaryMode()
    {
    }

};
