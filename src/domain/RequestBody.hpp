#pragma once

namespace getit
{
    template<typename InputDataType, typename OutputDataType>
    struct RequestBody
    {
        public:
            virtual ~IRequestBody() = default;
            virtual void setData(InputDataType data) = 0;
            virtual void getData(): OutputDataType = 0;

        private:
            InputDataType data;
    };
}