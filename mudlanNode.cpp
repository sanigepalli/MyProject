#include <iostream>
#include "mudlanNodeMessages.h"

class NodeMessage {

  public:
    solitaryNodeMessage(nodeType nt) {

       if (nt == solitaryNode ) {
         packetBuffer = malloc(SOLITARYNODEMESSAGE_LENGTH);
         if (packetBuffer == NULL )
            cout << " Memory Allocation failed " << endl;
       } else  {
           cout << " No code to handle different messages" << endl;
       }

       resetPacketBuffer();

    }

    bool setPacketField(unsigned int *value,unsigned int offset,  int numBits)
    {
        int arrayOffset,startBitNum,stopBitNum;
        arrayOffset=discoveryJoinMessageTable[offset][0];
        startBitNum=discoveryJoinMessageTable[offset][1];
        stopBitNum=discoveryJoinMessageTable[offset][2];

        if(checkBitOffsets(numBits,startBitNum,stopBitNum))
          return(false);
        
        int mask = getBitMask(numBits,startBitNum);

        int packetOrigValue;
        packetOrigValue=packetBuffer[arrayOffset];
        packetOrigValue &= mask;

        packetOrigValue |=  *value << startBitNum;

        return(true);
    }

    bool getPacketField(unsigned int *value,unsigned int offset, int numBits)
    {
        int arrayOffset,startBitNum,stopBitNum;
        arrayOffset=discoveryJoinMessageTable[offset][0];
        startBitNum=discoveryJoinMessageTable[offset][1];
        stopBitNum=discoveryJoinMessageTable[offset][2];

        if(checkBitOffsets(numBits,startBitNum,stopBitNum))
          return(false);
        
        int mask = getBitMask(numBits,startBitNum);

        int packetOrigValue;
        packetOrigValue=packetBuffer[arrayOffset];
        packetOrigValue &= mask;

        *value=packetOrigValue>>startBitNum;

        return(true);

    }

    void resetPacketBuffer()
    {
        if (packetBuffer != NULL ) {
          for (i=0; i<SOLITARYNODEMESSAGE_LENGTH;i++)
              packetBuffer[i]=0;
        } else {
            cout << "Packet Buffer is null " << endl;
        } 
    }

    unsigned int getPacketSize();
     {
         return(SOLITARYNODEMESSAGE_LENGTH);
     }

    bool receiveMessage(unsigned char*receivedMsg, int length) 
    {
        if (length != getPacketSize())
          return(false);
        
        for (int i=0; i<length; i++)
            packetbuffer[i]=receivedMsg[i];
    }
    bool sendMessage() 
    {
        cout << "Printing the complete packet " << endl;
        for (int i=0; i<getPacketSize(); i++)

    }

    bool sendMessage(unsigned int *recvPacket,int length) 
    {
        if (length != getPacketSize())
           return(false);
        for (int i=0; i<length; i++)
           recvPacket[i]=packetBuffer[i];
    }
    bool getLatitude(unsigned int *result, int numBits)
    {
        *result=packetBuffer[LATITUDE_WORD_INDEX];
        return(true);
    }

    bool setLatitude(unsigned int *input, int numBits)
    {
        packetBuffer[LATITUDE_WORD_INDEX]=*input;
        return(true);
    }
    bool getLongitude(unsigned int *result, int numBits) {
        *result=packetBuffer[LONGITUDE_WORD_INDEX];
        return(true);
    }
    bool setLongitude(unsigned int *input, int numBits){
        packetBuffer[LONGITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool getAltitude(unsigned int *result, int numBits) {
        *result=packetBuffer[ALTITUDE_WORD_INDEX];
        return(true);
    }
    bool setAltitude(unsigned char *input, int numBits){
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool getRequestingNodeId(unsigned int *result, int numBits)
    {
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool setRequestingNodeId(unsigned int *input, int numBits)
    {
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool getRequestingNetworkNodeId(unsigned int *result, int numBits){
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool setRequestingNetworkNodeId(unsigned int *input, int numBits){
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool getTargetNodeId(unsigned int *result, int numBits)
    {
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

    bool setTargetNodeId(unsigned int *input, int numBits)
    {
        packetBuffer[ALTITUDE_WORD_INDEX]=*input;
        return(true);
    }

};