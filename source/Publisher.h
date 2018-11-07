#ifndef PUBLISHER_H
#define PUBLISHER_H

#include "Subscriber.h"
#include <vector>

template <class PublishType> class Publisher
{
    public:
        void addSubscriber(Subscriber<PublishType>);
    protected:
        void publish(PublishType);
    private:
        std::vector<Subscriber<PublishType>> subscribers;
};

#endif
