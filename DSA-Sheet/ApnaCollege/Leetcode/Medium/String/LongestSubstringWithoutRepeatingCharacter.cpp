#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int size = s.length();
        int count = 0;
        for(int i = 0;i<size;i++){
            vector<bool> vis(MAX_CHAR,false);
            for(int j = i;j<size;j++){
                
            }
        }
    }
};
int main(){
    string s;
    cin>>s;

    Solution solution;
    int result = solution.lengthOfLongestSubstring(s);
    cout<<result;

    return 0;
}



private void upd_image_Click(object sender, EventArgs e)
 {
     // Open File Dialog to select an image
     using (OpenFileDialog openFileDialog = new OpenFileDialog())
     {
         openFileDialog.Filter = "Image Files|.jpg;.jpeg;.png;.bmp";
         openFileDialog.Title = "Select an Image";

         if (openFileDialog.ShowDialog() == DialogResult.OK)
         {
             // Get the file info
             FileInfo fileInfo = new FileInfo(openFileDialog.FileName);

             // Validate file size (4MB = 4 * 1024 * 1024 bytes)
             if (fileInfo.Length > 4 * 1024 * 1024)
             {
                 MessageBox.Show("The selected image exceeds the size limit of 4MB. Please choose a smaller file.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                 return;
             }

             // Display the image in the PictureBox
             profile_image.Image = Image.FromFile(openFileDialog.FileName);
             profile_image.SizeMode = PictureBoxSizeMode.Zoom;

             // Show the Progress Bar and simulate upload
             pgr_bar.Visible = true;
             pgr_bar.Value = 0;

             // Simulate upload progress
             for (int i = 0; i <= 100; i += 10)
             {
                 pgr_bar.Value = i;
                 System.Threading.Thread.Sleep(50); // Simulates upload delay
             }

             pgr_bar.Visible = false; // Hide the progress bar after upload is complete
             MessageBox.Show("Image uploaded successfully!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
         }
     }
 }