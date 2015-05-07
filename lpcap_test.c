#include <pcap.h>
#include <stdio.h>
#include <arpa/inet.h>

#define SIZE_ETHERNET 14

    /* IP header */
    struct sniff_ip {
        u_char ip_vhl;     		
        u_char ip_tos;      		
        u_short ip_len;     		
        u_short ip_id;      		
        u_short ip_off;     		
    	#define IP_RF 0x8000        /* reserved fragment flag */
    	#define IP_DF 0x4000        /* dont fragment flag */
    	#define IP_MF 0x2000        /* more fragments flag */
    	#define IP_OFFMASK 0x1fff   /* mask for fragmenting bits */
        u_char ip_ttl;      
        u_char ip_p;       
        u_short ip_sum;    
        struct in_addr ip_src; /* source address */
        struct in_addr ip_dst; /* destination address */
    };
 
int main()
{
    pcap_t *handle; 
    char *dev;
    char *net;
    char *mask;
    char errbuf[PCAP_ERRBUF_SIZE];
    bpf_u_int32 mask1;
    bpf_u_int32 net1;
    struct pcap_pkthdr header;
    const u_char *packet;
    const struct sniff_ip *ip;
    struct in_addr addr;
    int a = 1;
 
    /* find device */
    dev = pcap_lookupdev(errbuf);
    printf("DEV: %s\n", dev);
    /* find the properties for the device */
    pcap_lookupnet(dev, &net1, &mask1, errbuf);
    
    /* get net and mask from properties*/
    addr.s_addr = net1;
    net = inet_ntoa(addr);
    printf("NET: %s\n",net);

    addr.s_addr = mask1;
    mask = inet_ntoa(addr);
    printf("MASK: %s\n",mask);
    printf("\n");

    /* new live session */
    handle = pcap_open_live(dev, BUFSIZ, 1, 0, errbuf);
    
    do{
        printf("packet # %d\n", a);
    /* new packet */
        packet = pcap_next(handle, &header);
    /* print its length */
        printf("Got a packet with length of [%d]\n", header.len);
        ip = (struct sniff_ip*)(packet + SIZE_ETHERNET);
    /* get ip addresses from ip_header */   
        printf("source address: %s \n",  inet_ntoa(ip->ip_src));
        printf("destination address: %s \n",  inet_ntoa(ip->ip_dst));
        printf("\n");

    /* next iteration */
        a = a + 1;
    }while ( a < 11 );

    /* close the session */
    pcap_close(handle);
    return(0);
}
