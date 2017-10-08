package CUDAWrapper.runtime;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.driver.CUevent;

/**
 * Java port of a cudaEvent_t.
 *
 * @see CUDAWrapper#cudaEventCreate
 * @see CUDAWrapper#cudaEventDestroy
 * @see CUDAWrapper#cudaEventElapsedTime
 * @see CUDAWrapper#cudaEventQuery
 * @see CUDAWrapper#cudaEventRecord
 * @see CUDAWrapper#cudaEventSynchronize
 */
public class cudaEvent_t extends NativePointerObject
{
    /**
     * Creates a new, uninitialized cudaEvent_t
     */
    public cudaEvent_t()
    {
    }

    /**
     * Creates a cudaEvent_t for the given {@link CUevent}. This
     * corresponds to casting a CUevent to a cudaEvent_t.
     *
     * @param event The other event
     */
    public cudaEvent_t(CUevent event)
    {
        super(event);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "cudaEvent_t["+
            "nativePointer="+getNativePointer()+"]";
    }

}
