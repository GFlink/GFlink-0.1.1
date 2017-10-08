package CUDAWrapper.runtime;


/**
 * Java port of a cudaIpcEventHandle.
 */
public class cudaIpcEventHandle
{
    private static final int CUDA_IPC_HANDLE_SIZE = 64;

    // This field is only used on the native side. Nobody
    // knows whether CUDA already uses this data, but
    // presumably, it does
    @SuppressWarnings("unused")
    private byte reserved[] = new byte[CUDA_IPC_HANDLE_SIZE];

    /**
     * Creates a new, uninitialized cudaIpcEventHandle
     */
    public cudaIpcEventHandle()
    {
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return super.toString();
    }

}
