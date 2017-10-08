

package CUDAWrapper.runtime;

/**
 * Memcpy kinds.
 *
 * @see CUDAWrapper#cudaMemcpy
 * @see cudaMemcpy3DParms
 */
public class cudaMemcpyKind
{

    /**
     * Host   -> Host
     */
    public static final int cudaMemcpyHostToHost = 0;

    /**
     * Host   -> Device
     */
    public static final int cudaMemcpyHostToDevice = 1;

    /**
     * Device -> Host
     */
    public static final int cudaMemcpyDeviceToHost = 2;

    /**
     * Device -> Device
     */
    public static final int cudaMemcpyDeviceToDevice = 3;

    /**
     * Direction of the transfer is inferred from the pointer values.
     * Requires unified virtual addressing.
     */
    public static final int cudaMemcpyDefault = 4;

    /**
     * Returns the String identifying the given cudaMemcpyKind
     *
     * @param k The cudaMemcpyKind
     * @return The String identifying the given cudaMemcpyKind
     */
    public static String stringFor(int k)
    {
        switch (k)
        {
            case cudaMemcpyHostToHost: return "cudaMemcpyHostToHost";
            case cudaMemcpyHostToDevice: return "cudaMemcpyHostToDevice";
            case cudaMemcpyDeviceToHost: return "cudaMemcpyDeviceToHost";
            case cudaMemcpyDeviceToDevice: return "cudaMemcpyDeviceToDevice";
            case cudaMemcpyDefault: return "cudaMemcpyDefault";
        }
        return "INVALID cudaMemcpyKind: "+k;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaMemcpyKind()
    {
    }

}
