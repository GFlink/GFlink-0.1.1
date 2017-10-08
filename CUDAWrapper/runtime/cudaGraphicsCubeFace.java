package CUDAWrapper.runtime;

/**
 * CUDA graphics interop array indices for cube maps
 */
public class cudaGraphicsCubeFace
{

    /**
     * Positive X face of cubemap
     */
    public static final int cudaGraphicsCubeFacePositiveX = 0x00;


    /**
     * Negative X face of cubemap
     */
    public static final int cudaGraphicsCubeFaceNegativeX = 0x01;


    /**
     * Positive Y face of cubemap
     */
    public static final int cudaGraphicsCubeFacePositiveY = 0x02;


    /**
     * Negative Y face of cubemap
     */
    public static final int cudaGraphicsCubeFaceNegativeY = 0x03;


    /**
     * Positive Z face of cubemap
     */
    public static final int cudaGraphicsCubeFacePositiveZ = 0x04;


    /**
     * Negative Z face of cubemap
     */
    public static final int cudaGraphicsCubeFaceNegativeZ = 0x05;

    /**
     * Returns the String identifying the given cudaGraphicsCubeFace
     *
     * @param n The cudaGraphicsCubeFace
     * @return The String identifying the given cudaGraphicsCubeFace
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case cudaGraphicsCubeFacePositiveX: return "cudaGraphicsCubeFacePositiveX";
            case cudaGraphicsCubeFaceNegativeX: return "cudaGraphicsCubeFaceNegativeX";
            case cudaGraphicsCubeFacePositiveY: return "cudaGraphicsCubeFacePositiveY";
            case cudaGraphicsCubeFaceNegativeY: return "cudaGraphicsCubeFaceNegativeY";
            case cudaGraphicsCubeFacePositiveZ: return "cudaGraphicsCubeFacePositiveZ";
            case cudaGraphicsCubeFaceNegativeZ: return "cudaGraphicsCubeFaceNegativeZ";
        }
        return "INVALID cudaGraphicsCubeFace: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaGraphicsCubeFace()
    {
    }

}
