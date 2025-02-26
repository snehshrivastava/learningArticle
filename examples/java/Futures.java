import java.util.concurrent.CompletableFuture;

public class Futures {
    public static void main(String[] args) {
        CompletableFuture<String> future;
        try {
            future = CompletableFuture.supplyAsync(() -> {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                // if (true)
                //     throw new Error("Error inside future");
                return "Hello";
            }).exceptionally(ex -> {
                System.out.println(ex.getMessage());
                throw new Error(ex.getMessage());
            });
            future.thenAccept((val)->{
                System.out.println(val+" inside next task");
            });
            System.out.println(future.join());
            
        } catch (Exception e) {
            System.out.println(e.getMessage()+"jai mata di");
        }
    }
}
