#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

template <class SubscriptionType> class Subscriber
{
    public:
        virtual void publishTo(SubscriptionType) = 0;
};

#endif