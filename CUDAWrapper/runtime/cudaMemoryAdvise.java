
package CUDAWrapper.runtime;

/**
 * CUDA Memory Advise values
 */
public class cudaMemoryAdvise
{
    /**
     * Data will mostly be read and only occassionally be written to 
     */
    public static final int cudaMemAdviseSetReadMostly          = 1;

    /**
     * Undo the effect of ::cudaMemAdviseSetReadMostly 
     */
    public static final int cudaMemAdviseUnsetReadMostly        = 2;

    /**
     * Set the preferred location for the data as the specified device 
     */
    public static final int cudaMemAdviseSetPreferredLocation   = 3;

    /**
     * Clear the preferred location for the data 
     */
    public static final int cudaMemAdviseUnsetPreferredLocation = 4;

    /**
     * Data will be accessed by the specified device, so prevent page faults as much as possible 
     */
    public static final int cudaMemAdviseSetAccessedBy          = 5;

    /**
     * Let the Unified Memory subsystem decide on the page faulting policy for the specified device 
     */
    public static final int cudaMemAdviseUnsetAccessedBy        = 6;

    /**
     * Returns the String identifying the given cudaMemoryAdvise
     *
     * @param k The cudaMemoryAdvise
     * @return The String identifying the given cudaMemoryAdvise
     */
    public static String stringFor(int k)
    {
        switch (k)
        {
            case cudaMemAdviseSetReadMostly : return "cudaMemAdviseSetReadMostly";
            case cudaMemAdviseUnsetReadMostly : return "cudaMemAdviseUnsetReadMostly";
            case cudaMemAdviseSetPreferredLocation : return "cudaMemAdviseSetPreferredLocation";
            case cudaMemAdviseUnsetPreferredLocation : return "cudaMemAdviseUnsetPreferredLocation";
            case cudaMemAdviseSetAccessedBy : return "cudaMemAdviseSetAccessedBy";
            case cudaMemAdviseUnsetAccessedBy : return "cudaMemAdviseUnsetAccessedBy";
        }
        return "INVALID cudaMemoryAdvise: "+k;
    }


    /**
     * Private constructor to prevent instantiation.
     */
    private cudaMemoryAdvise()
    {

    }
};
