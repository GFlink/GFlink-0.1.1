
package CUDAWrapper.runtime;

import CUDAWrapper.Pointer;

/**
 * CUDA pointer attributes
 */
public class cudaPointerAttributes
{
    /**
     * The physical location of the memory, ::cudaMemoryTypeHost or
     * ::cudaMemoryTypeDevice.
     */
    public int memoryType;

    /**
     * The device against which the memory was allocated or registered.
     * If the memory type is ::cudaMemoryTypeDevice then this identifies
     * the device on which the memory referred physically resides.  If
     * the memory type is ::cudaMemoryTypeHost then this identifies the
     * device which was current when the memory was allocated or registered
     * (and if that device is deinitialized then this allocation will vanish
     * with that device's state).
     */
    public int device;

    /**
     * The address which may be dereferenced on the current device to access
     * the memory or NULL if no such address exists.
     */
    public Pointer devicePointer = new Pointer();

    /**
     * The address which may be dereferenced on the host to access the
     * memory or NULL if no such address exists.
     */
    public Pointer hostPointer = new Pointer();

    /**
     * Indicates if this pointer points to managed memory
     */
    public int isManaged;

    /**
     * Creates a new, uninitialized cudaPointerAttributes
     */
    public cudaPointerAttributes()
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
        return "cudaPointerAttributes["+
            "memoryType="+cudaMemoryType.stringFor(memoryType)+","+
            "device="+device+","+
            "devicePointer="+devicePointer+","+
            "hostPointer="+hostPointer+"," +
            "isManaged="+isManaged+"]";
    }

};