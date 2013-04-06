#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>

std::queue<int> queue;
std::stack<int> stack;
std::priority_queue<int> priority_queue;

int main()
{
    int num;

    while( scanf( "%d", &num ) != EOF )
    {
        bool is_queue = true;
        bool is_stack = true;
        bool is_priority = true;

        while( !queue.empty() )
            queue.pop();
        while( !stack.empty() )
            stack.pop();
        while( !priority_queue.empty() )
            priority_queue.pop();

        for( int i = 0, now, ans; i < num; i++ )
        {
            scanf( "%d%d", &now, &ans );

            switch( now )
            {
                case 1:
                    queue.push( ans );
                    stack.push( ans );
                    priority_queue.push( ans );
                    break;
                case 2:
                    if( queue.empty() || queue.front() != ans )
                        is_queue = false;
                    if( stack.empty() || stack.top() != ans )
                        is_stack = false;
                    if( priority_queue.empty() || priority_queue.top() != ans )
                        is_priority = false;

                    if( is_queue )
                        queue.pop();
                    if( is_stack )
                        stack.pop();
                    if( is_priority )
                        priority_queue.pop();
                    break;
            }
        }


        int sum = 0;

        if( is_queue )
            sum++;
        if( is_stack )
            sum++;
        if( is_priority )
            sum++;

        switch( sum )
        {
            case 0:
                printf( "impossible\n");
                break;
            case 1:
                if( is_queue )
                    printf( "queue\n");
                if( is_stack )
                    printf( "stack\n");
                if( is_priority )
                    printf( "priority queue\n");
                break;
            default:
                printf( "not sure\n");
                break;
        }
    }

    return 0;
}


