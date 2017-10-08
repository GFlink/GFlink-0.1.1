
package CUDAWrapper.runtime;

import CUDAWrapper.Pointer;

/**
 * Java port of a cudaPitchedPtr
 *
 * @see CUDAWrapper#cudaMalloc3D(cudaPitchedPtr, cudaExtent)
 * @see CUDAWrapper#cudaMemcpy3D(cudaMemcpy3DParms)
 * @see CUDAWrapper#cudaMemset3D(cudaPitchedPtr, int, cudaExtent)
 */
public class cudaPitchedPtr
{
    /**
     * Pointer to allocated memory.
     */
    public Pointer ptr = new Pointer();

    /**
     * The pitch of the pointer, in bytes
     */
    public long pitch;

    /**
     * xsize and ysize, the logical width and height of the, are equivalent to the
     * width and height extent parameters provided by the programmer during allocation
     */
    public long xsize;

    /**
     * xsize and ysize, the logical width and height of the, are equivalent to the
     * width and height extent parameters provided by the programmer during allocation
     */
    public long ysize;

    /**
     * Creates a new, uninitialized cudaPitchedPtr
     */
    public cudaPitchedPtr()
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
        return "cudaPitchedPtr["+
            "ptr="+ptr+","+
            "pitch="+pitch+","+
            "xsize="+xsize+","+
            "ysize="+ysize+"]";
    }

}
