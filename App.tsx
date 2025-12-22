import React from 'react';

export default function App() {
  return (
    <div className="min-h-screen flex items-center justify-center p-4 font-sans">
      <div className="w-full max-w-lg bg-white p-8 rounded-xl shadow-lg border border-gray-200">
        
        <h1 className="text-3xl font-bold text-center mb-2 text-gray-900">Project I</h1>
        <p className="text-center text-gray-500 mb-8">Danh sách các dự án con</p>
        
        <div className="flex flex-col gap-4">
          {/* Link Project 1 */}
          <a 
            href="./folder1/index.html" 
            className="block w-full p-4 bg-gray-50 hover:bg-blue-50 border border-gray-200 hover:border-blue-500 rounded-lg transition-colors text-center"
          >
            <span className="text-lg font-semibold text-gray-800 hover:text-blue-700">Project Folder 1</span>
          </a>

          {/* Link Project 2 */}
          <a 
            href="./folder2/index.html" 
            className="block w-full p-4 bg-gray-50 hover:bg-green-50 border border-gray-200 hover:border-green-500 rounded-lg transition-colors text-center"
          >
            <span className="text-lg font-semibold text-gray-800 hover:text-green-700">Project Folder 2</span>
          </a>

          {/* Link Project 3 */}
          <a 
            href="./folder3/index.html" 
            className="block w-full p-4 bg-gray-50 hover:bg-purple-50 border border-gray-200 hover:border-purple-500 rounded-lg transition-colors text-center"
          >
            <span className="text-lg font-semibold text-gray-800 hover:text-purple-700">Project Folder 3</span>
          </a>

          {/* Link Project 4 */}
          <a 
            href="./folder4/index.html" 
            className="block w-full p-4 bg-gray-50 hover:bg-orange-50 border border-gray-200 hover:border-orange-500 rounded-lg transition-colors text-center"
          >
            <span className="text-lg font-semibold text-gray-800 hover:text-orange-700">Project Folder 4</span>
          </a>
        </div>

        <div className="mt-8 pt-4 border-t border-gray-100 text-center text-sm text-gray-400">
          © Project I Repository
        </div>
      </div>
    </div>
  );
}