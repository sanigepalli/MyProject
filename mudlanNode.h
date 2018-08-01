#include <iostream>
#include <mudlanNodeMessages.h>

#define MESSAGE_WORD_LENGTH 4 
#define SOLITARYNODEMESSAGE_LENGTH 36*MESSAGE_WORD_LENGTH

class nodeMessage {

    public:
            nodeMessage();
            bool setPacketField(unsigned int *value,unsigned int offset,  int numBits);
            bool getPacketField(unsigned int *value,unsigned int offset,  int numBits);
            void resetPacketBuffer();
            unsigned int getPacketSize();
            bool receiveMessage(unsigned char*receivedMsg);
            bool sendMessage();
			bool getLatitude(unsigned int *result, int numBits);
			bool setLatitude(unsigned int *input, int numBits);
			bool getLongitude(unsigned int *result, int numBits);
            bool setLongitude(unsigned int *input, int numBits);
            bool getAltitude(unsigned int *result, int numBits);
			bool setAltitude(unsigned int *input, int numBits);
			bool getRequestingNodeId(unsigned int *result, int numBits);
			bool setRequestingNodeId(unsigned int *input, int numBits);
			bool getRequestingNetworkNodeId(unsigned int *result, int numBits);
			bool setRequestingNetworkNodeId(unsigned int *input, int numBits);
			bool getTargetNodeId(unsigned int *result, int numBits);
			bool setTargetNodeId(unsigned int *input, int numBits);

    protected:
         unsigned char *packetBuffer;
         int packetSize;

};

class solitaryNodeMessage: public node {
    public:
           solitaryNodeMessage(nodeType nt);
}

class pgmNodeMessage : public Node  {
   public:
       pgmNodeMessage(peerGroupMessageType pt);
}

class pglNodeMessage : public Node  {
public:
    pglNodeMessage(peerGroupMessageType pt);
}
