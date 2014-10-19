import java.awt.*;
import javax.swing.*;

/** Custom Drawing Code Template */ 
@SuppressWarnings("serial")
public class CGTemplate extends JFrame {  // Graphics application extends JFrame
   // Named-constants for dimensions
   public static final int CANVAS_WIDTH = 640;
   public static final int CANVAS_HEIGHT = 480;
 
   private DrawCanvas canvas;  // Declare an instance the drawing canvas (extends JPanel)
 
   /** Constructor to set up the GUI components */
   public CGTemplate() {
      canvas = new DrawCanvas();    // Construct the drawing canvas
      canvas.setPreferredSize(new Dimension(CANVAS_WIDTH, CANVAS_HEIGHT));
      this.setContentPane(canvas);   
         // Set the Drawing JPanel as the content-pane
         // OR 
         // Get the JFrame's content-pane and add onto the content-pane as follows:
         //   Container cp = getContentPane();
         //   cp.add(canvas);
 
      this.setDefaultCloseOperation(EXIT_ON_CLOSE);   // Handle the CLOSE button
      this.pack();              // Either pack() the components; or setSize()
      this.setTitle("......");  // this JFrame sets the title
      this.setVisible(true);    // this JFrame show
   }
 
   /**
    * DrawCanvas (inner class) is a JPanel used for custom drawing
    */
   private class DrawCanvas extends JPanel {
      // Override paintComponent to perform your own painting
      @Override
      public void paintComponent(Graphics g) {
         super.paintComponent(g);     // paint parent's background
         setBackground(Color.BLACK);  // set background color for this JPanel
 
         // Your custom painting codes. For example,
         // Drawing primitive shapes
         g.setColor(Color.YELLOW);    // set the drawing color
         g.drawLine(30, 40, 100, 200);
         g.drawOval(150, 180, 10, 10);
         g.drawRect(200, 210, 20, 30);
         g.setColor(Color.RED);       // change the drawing color
         g.fillOval(300, 310, 30, 50);
         g.fillRect(400, 350, 60, 50);
         // Printing texts
         g.setColor(Color.WHITE);
         g.setFont(new Font("Courier New", Font.PLAIN, 12));
         g.drawString("Testing custom drawing ...", 10, 20);
      }
   }
 
   /** Entry main method */
   public static void main(String[] args) {
      // Run the GUI codes on the Event-Dispatching thread for thread safety
      SwingUtilities.invokeLater(new Runnable() {
         @Override
         public void run() {
            new CGTemplate(); // Let the constructor do the job
         }
      });
   }
}
