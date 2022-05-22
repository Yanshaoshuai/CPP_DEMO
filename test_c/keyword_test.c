int count;

int plus_count(){
    count++;
}

static static_count;
static int static_plus_count(){
    static_count++;
}

int local_static_variable(){
    static count;
    printf("local_static_variable hash been called %d times\n",++count);
}