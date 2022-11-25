else{
        struct node* head1=*head;
        while(head1!=NULL){
            count++;
            if(count==n-1){
                if(head1->link!=NULL){
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter value:");
                scanf("%d",&temp->data);
                temp->link=head1->link;
                head1->link=temp;
                break;
                }
                
            }
            else{
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter value:");
                scanf("%d",&temp->data);
                head1->link=temp;
                temp->link=NULL;
            }
            printf("%d:%d\n",count,head1->data);
            head1=head1->link;

        }