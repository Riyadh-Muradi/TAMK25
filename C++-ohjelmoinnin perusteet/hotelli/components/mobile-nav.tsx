"use client";

import { useState, useCallback, useRef, useEffect } from "react";
import { useTab } from "@/components/tab-provider";

import { Button } from "@/components/ui/button";
import { cn } from "@/lib/utils";
import { TextAlignStart, X } from "lucide-react";
import { ThemeSwitcher } from "@/components/theme-switcher";

type NavItem = { label: string };
type TabType = "yleiskatsaus" | "varaus" | "haku";

const TAB_ORDER: TabType[] = ["yleiskatsaus", "varaus", "haku"];

export default function MobileNav({
  items,
  className,
}: {
  items: NavItem[];
  className?: string;
}) {
  const { activeTab, setActiveTab } = useTab();
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);
  const containerRef = useRef<HTMLDivElement | null>(null);
  const [panelTop, setPanelTop] = useState<number | null>(null);
  const [panelLeft, setPanelLeft] = useState<number | null>(null);
  const [panelWidth, setPanelWidth] = useState<number | null>(null);

  const toggleMobileMenu = useCallback(() => {
    setMobileMenuOpen((v) => !v);
  }, []);

  const handleTabClick = useCallback(
    (index: number) => {
      const tab = TAB_ORDER[index];
      setActiveTab(tab);
      setMobileMenuOpen(false);
    },
    [setActiveTab],
  );

  // update panelTop when menu opens and on resize/scroll so the panel sits under the header
  useEffect(() => {
    if (!mobileMenuOpen) {
      return;
    }

    const updateTop = () => {
      const header = document.querySelector("header");
      if (header) {
        // find the centered inner container (the one with the max-w class)
        const inner =
          header.querySelector('[class*="max-w-screen-lg"]') ||
          header.querySelector("div");
        const rect = inner
          ? inner.getBoundingClientRect()
          : header.getBoundingClientRect();
        // Use viewport coordinates (rect values) so placement follows header even when banner toggles
        setPanelTop(rect.bottom);
        setPanelLeft(rect.left);
        setPanelWidth(rect.width);
      }
    };

    updateTop();
    window.addEventListener("resize", updateTop);

    // observe size changes of the header/inner container (covers banner show/hide animations)
    const headerEl = document.querySelector("header");
    const innerEl =
      headerEl?.querySelector('[class*="max-w-screen-lg"]') || null;
    let ro: ResizeObserver | null = null;
    if (typeof ResizeObserver !== "undefined") {
      ro = new ResizeObserver(updateTop);
      if (headerEl) ro.observe(headerEl);
      if (innerEl) ro.observe(innerEl);
    }

    return () => {
      window.removeEventListener("resize", updateTop);
      if (ro) ro.disconnect();
    };
  }, [mobileMenuOpen]);

  return (
    <div className={cn("relative", className)} ref={containerRef}>
      <Button
        size="icon"
        variant="outline"
        className="bg-background! hover:bg-muted! border-border/75! hover:border-none lg:hidden"
        onClick={toggleMobileMenu}
        aria-expanded={mobileMenuOpen}
      >
        {mobileMenuOpen ? (
          <X className="text-muted-foreground" />
        ) : (
          <TextAlignStart className="text-muted-foreground" />
        )}
      </Button>

      {mobileMenuOpen && (
        <div
          className="fixed z-50 mt-2 lg:hidden"
          style={
            panelTop !== null && panelLeft !== null && panelWidth !== null
              ? { top: panelTop, left: panelLeft, width: panelWidth }
              : panelTop !== null
                ? { top: panelTop, left: 0, right: 0 }
                : undefined
          }
        >
          <div
            id="mobile-nav-panel"
            role="dialog"
            aria-modal="true"
            aria-label="Päävalikko"
            className="bg-background border-border/75 w-full overflow-hidden rounded-2xl border p-3 shadow-xs"
          >
            <nav className="flex flex-col gap-2">
              <div className="flex flex-col gap-3">
                <div className="flex flex-col gap-1">
                  <span className="text-muted-foreground text-xs">Linkit</span>
                  <div className="mt-1 flex flex-col gap-2">
                    {items.map((item, index) => {
                      const tab = TAB_ORDER[index] as TabType;
                      const isActive = activeTab === tab;

                      return (
                        <div key={item.label}>
                          <Button
                            variant={isActive ? "default" : "ghost"}
                            size="sm"
                            className="w-full justify-start"
                            onClick={() => handleTabClick(index)}
                          >
                            {item.label}
                          </Button>
                        </div>
                      );
                    })}
                  </div>
                </div>
              </div>
              <div className="border-border/50 mt-2 flex flex-col gap-2 border-t pt-2">
                <div className="flex items-center justify-between">
                  <ThemeSwitcher />
                </div>
              </div>
            </nav>
          </div>
        </div>
      )}
    </div>
  );
}
