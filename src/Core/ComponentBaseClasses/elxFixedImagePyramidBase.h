#ifndef __elxFixedImagePyramidBase_h
#define __elxFixedImagePyramidBase_h

/** Needed for the macros */
#include "elxMacro.h"

#include "elxBaseComponentSE.h"
#include "itkObject.h"
#include "itkMultiResolutionPyramidImageFilter.h"


namespace elastix
{
using namespace itk;

	/**
	 * \class FixedImagePyramidBase
	 * \brief This class is based on the itk::MultiResolutionPyramidImageFilter.
	 *
	 * This class contains all the common functionality for FixedImagePyramids.
	 *
	 * \ingroup ImagePyramids
	 * \ingroup ComponentBaseClasses
	 */

	template <class TElastix>
		class FixedImagePyramidBase : public BaseComponentSE<TElastix>
	{
	public:

		/** Standard ITK-stuff. */
		typedef FixedImagePyramidBase				Self;
		typedef BaseComponentSE<TElastix>		Superclass;

		/** Run-time type information (and related methods). */
		itkTypeMacro( FixedImagePyramidBase, BaseComponentSE );

		/** Typedefs inherited from the superclass. */
		typedef typename Superclass::ElastixType						ElastixType;
		typedef typename Superclass::ElastixPointer					ElastixPointer;
		typedef typename Superclass::ConfigurationType			ConfigurationType;
		typedef typename Superclass::ConfigurationPointer		ConfigurationPointer;
		typedef typename Superclass::RegistrationType				RegistrationType;
		typedef typename Superclass::RegistrationPointer		RegistrationPointer;

		/** Typedefs inherited from Elastix. */
		typedef typename ElastixType::FixedInternalImageType	InputImageType;
		typedef typename ElastixType::FixedInternalImageType	OutputImageType;
			
		/** Used in the function GetFixedSchedule. */
		typedef typename ElastixType::MovingInternalImageType MovingImageType;
		
		/** Other typedef's. */
		typedef MultiResolutionPyramidImageFilter<
			InputImageType, OutputImageType >									ITKBaseType;

		/** Typedef's from ITKBaseType. */
		typedef typename ITKBaseType::ScheduleType					ScheduleType;

		/** Cast to ITKBaseType. */
		virtual ITKBaseType * GetAsITKBaseType(void)
		{
			return dynamic_cast<ITKBaseType *>(this);
		}

		/** Execute stuff before the actual registration:
		 * \li Set the schedule of the fixed image pyramid.
		 */
		virtual void BeforeRegistrationBase(void);

		/** Method for setting the schedule. */
		virtual void SetFixedSchedule(void);

	protected:

		/** The constructor. */
		FixedImagePyramidBase() {}
		/** The destructor. */
		virtual ~FixedImagePyramidBase() {}
		
	private:

		/** The private constructor. */
		FixedImagePyramidBase( const Self& );	// purposely not implemented
		/** The private copy constructor. */
		void operator=( const Self& );				// purposely not implemented

	}; // end class FixedImagePyramidBase


} // end namespace elastix



#ifndef ITK_MANUAL_INSTANTIATION
#include "elxFixedImagePyramidBase.hxx"
#endif


#endif // end #ifndef __elxFixedImagePyramidBase_h

