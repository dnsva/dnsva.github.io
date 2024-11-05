const units = {
    'A Space, time and motion': [
        'A.1 Kinematics',
        'A.2 Forces and momentum',
        'A.3 Work, energy and power',
        'A.4 Rigid body mechanics',
        'A.5 Galilean and special relativity'
    ],
    'B The particulate nature of matter': [
        'B.1 Thermal energy transfers',
        'B.2 Greenhouse effect',
        'B.3 Gas laws',
        'B.4 Thermodynamics',
        'B.5 Current and circuits'
    ],
    'Tools for physics': [
        'Mathematical tools for physics',
        'Experimental tools for physics',
        'Data analysis and modelling physics'
    ],
    'C Wave behaviour': [
        'C.1 Simple harmonic motion',
        'C.2 Wave model',
        'C.3 Wave phenomena',
        'C.4 Standing waves and resonance',
        'C.5 Doppler effect'
    ],
    'D Fields': [
        'D.1 Gravitational fields',
        'D.2 Electric and magnetic fields',
        'D.3 Motion in electromagnetic fields',
        'D.4 Induction'
    ],
    'E Nuclear and quantum physics': [
        'E.1 Structure of the atom',
        'E.2 Quantum physics',
        'E.3 Radioactive decay',
        'E.4 Fission',
        'E.5 Fusion and stars'
    ]
};

function formatFileName(subunit) {
    // Handle special cases for tools section
    if (subunit.startsWith('Mathematical')) return 'tools-mathematical';
    if (subunit.startsWith('Experimental')) return 'tools-experimental';
    if (subunit.startsWith('Data')) return 'tools-data-analysis';

    // Handle regular units (A.1, B.2, etc.)
    return subunit.toLowerCase()
        .replace(/\s+/g, '-')     // Replace spaces with hyphens
        .replace(/\./g, '')       // Remove periods
        .replace(/[^a-z0-9-]/g, ''); // Remove any other special characters
}

async function loadContent(subunit) {
    const contentDiv = document.getElementById('content');
    const fileName = formatFileName(subunit);
    
    try {
        const response = await fetch(`content/${fileName}.html`);
        if (response.ok) {
            contentDiv.innerHTML = await response.text();
        } else {
            contentDiv.innerHTML = `
                <h1>${subunit}</h1>
                <p>Content coming soon...</p>
                <p class="error-details">File not found: content/${fileName}.html</p>
            `;
        }
    } catch (error) {
        console.error('Error loading content:', error);
        contentDiv.innerHTML = `
            <h1>Error</h1>
            <p>Failed to load content for ${subunit}</p>
            <p class="error-details">${error.message}</p>
        `;
    }
}

function createSidebar() {
    const unitList = document.querySelector('.unit-list');
    
    Object.entries(units).forEach(([unit, subunits]) => {
        const unitDiv = document.createElement('div');
        
        const unitButton = document.createElement('button');
        unitButton.className = 'unit-button';
        unitButton.textContent = unit;
        unitDiv.appendChild(unitButton);
        
        subunits.forEach(subunit => {
            const subunitButton = document.createElement('button');
            subunitButton.className = 'unit-button subunit';
            subunitButton.textContent = subunit;
            subunitButton.addEventListener('click', () => loadContent(subunit));
            unitDiv.appendChild(subunitButton);
        });
        
        unitList.appendChild(unitDiv);
    });
}

// Load default content or handle initial page load
function loadDefaultContent() {
    const firstSubunit = units['A Space, time and motion'][0];
    loadContent(firstSubunit);
}

document.addEventListener('DOMContentLoaded', () => {
    createSidebar();
    loadDefaultContent();

    // Sidebar resize functionality
    const sidebar = document.querySelector('.sidebar');
    const resizer = document.querySelector('.sidebar-resizer');
    const main = document.querySelector('main');
    
    let isResizing = false;
    
    resizer.addEventListener('mousedown', (e) => {
        isResizing = true;
        document.addEventListener('mousemove', handleMouseMove);
        document.addEventListener('mouseup', () => {
            isResizing = false;
            document.removeEventListener('mousemove', handleMouseMove);
        });
    });

    function handleMouseMove(e) {
        if (!isResizing) return;
        
        const newWidth = e.clientX;
        if (newWidth >= 200 && newWidth <= 600 && !sidebar.classList.contains('collapsed')) {
            sidebar.style.width = newWidth + 'px';
            main.style.marginLeft = newWidth + 'px';
            main.style.width = `calc(100% - ${newWidth}px)`;
        }
    }

    // Mobile sidebar toggle
    const toggleButton = document.querySelector('.sidebar-toggle');
    const overlay = document.querySelector('.sidebar-overlay');

    toggleButton.addEventListener('click', () => {
        if (window.innerWidth <= 768) {
            // Mobile behavior
            sidebar.classList.toggle('active');
            overlay.classList.toggle('active');
            // Remove desktop collapse class when in mobile
            sidebar.classList.remove('collapsed');
            main.classList.remove('expanded');
        } else {
            // Desktop behavior
            sidebar.classList.toggle('collapsed');
            main.classList.toggle('expanded');
            // Remove mobile classes when in desktop
            sidebar.classList.remove('active');
            overlay.classList.remove('active');
        }
    });

    overlay.addEventListener('click', () => {
        sidebar.classList.remove('active');
        overlay.classList.remove('active');
    });

    // Close sidebar when clicking a link on mobile
    const sidebarLinks = document.querySelectorAll('.unit-button');
    sidebarLinks.forEach(link => {
        link.addEventListener('click', () => {
            if (window.innerWidth <= 768) {
                sidebar.classList.remove('active');
                overlay.classList.remove('active');
            }
        });
    });

    // Handle window resize
    window.addEventListener('resize', () => {
        if (window.innerWidth > 768) {
            // Remove mobile classes when switching to desktop
            overlay.classList.remove('active');
            sidebar.classList.remove('active');
        } else {
            // Remove desktop classes when switching to mobile
            sidebar.classList.remove('collapsed');
            main.classList.remove('expanded');
        }
    });
});
