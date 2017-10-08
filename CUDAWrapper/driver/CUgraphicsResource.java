

package CUDAWrapper.driver;

import CUDAWrapper.NativePointerObject;
import CUDAWrapper.runtime.cudaGraphicsResource;

/**
 * Java port of a CUgraphicsResource.
 */
public class CUgraphicsResource extends NativePointerObject
{
    /**
     * Creates a new, uninitialized CUgraphicsResource
     */
    public CUgraphicsResource()
    {
    }

    /**
     * Creates a CUgraphicsResource for the given {@link cudaGraphicsResource}. This
     * corresponds to casting a cudaGraphicsResource to a CUgraphicsResource.
     *
     * @param resource The other resource
     */
    public CUgraphicsResource(cudaGraphicsResource resource)
    {
        super(resource);
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUgraphicsResource["+
            "nativePointer=0x"+Long.toHexString(getNativePointer())+"]";
    }

}
